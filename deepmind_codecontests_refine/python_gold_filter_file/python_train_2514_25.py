n = int(input())
nu = list(map(int,list(input())))
a = [0] + list(map(int,input().split()))

#print(nu)
for i in range(n):
    t = nu[i]
    if t<a[t]:
        while i<n and t<=a[t]:
            nu[i] = a[t]
            i+=1
            if i<n:
                t = nu[i]
        break

print(''.join(str(x) for x in nu))
n = int(input())
s = input()
count = 0
for i in range(1000):
    v = str(i).zfill(3)
    k=0
    for j in range(n):
        if v[k] == s[j]:
            k+=1
        if k==3:
            count+=1
            break

print(count)
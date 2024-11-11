info= [int(i) for i in input().split()]
n= info[0]
m=info[1]
f = [int(i) for i in input().split()][:m]
f.sort()
j=n-1
mini = 3000000000000000000
for x in f:
    if j == m:
        break
    temp =f[j]-x
    mini = min(temp,mini)
    j=j+1

print(mini)
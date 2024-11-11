n=int(input())
m=int(input())
sb=[]
for i in range(n):
    sb.append(int(input()))
sb.sort()
step=0
for i in range(n-1,-1,-1):
    m-=sb[i]
    step+=1
    if m<=0:
        break
print(step)

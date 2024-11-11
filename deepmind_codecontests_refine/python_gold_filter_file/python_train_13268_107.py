s=int(input())
count=0
for i in range(s):
    p,q=map(int,input().split())
    if q-p>1:
        count+=1
print(count)
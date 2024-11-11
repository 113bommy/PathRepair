p=[]
n=int(input())
for i in range(n):
   a,b=map(int,input().split())
   p.append(b)
k=int(input())
for i in range(len(p)):
    if k<=p[i]:
        print(n-i)
        break
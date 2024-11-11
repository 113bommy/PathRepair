n=int(input())
a,b=map(int, input().split())
p=list(map(int, input().split()))
c=[0]*3
for i in p:
       if i <=a:
        c[0] +=1
       elif i>b:
        c[2] +=1
       else:
        c[1]+=1
print(min(c))
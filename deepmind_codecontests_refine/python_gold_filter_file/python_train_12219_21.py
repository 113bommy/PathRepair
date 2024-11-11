t=int(input())
n=list(map(int,input().split()))
a=0
b=0
c=0
i=0
while i<t:
    a=a+n[i]
    if i+1<t:
      b=b+n[i+1] 
    if i+2<t:
      c=c+n[i+2]
    i=i+3
dic={"chest":a,"biceps":b,"back":c}
print(max(dic, key=dic.get))
    
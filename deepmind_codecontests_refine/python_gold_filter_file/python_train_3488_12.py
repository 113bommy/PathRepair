k,a,b=map(int, input().split())
if a>0 and b>0:
    ans=b//k-(a-1)//k
elif a<0 and b<0:
    ans=abs(a)//k-abs(b+1)//k
elif a<=0 and b>=0:
    ans=abs(a)//k+b//k+1
print(ans)
    
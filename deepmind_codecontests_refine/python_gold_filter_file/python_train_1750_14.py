h,w,n=map(int,input().split())
sr,sc=map(int,input().split())
s=input()[::-1]
t=input()[::-1]
l,r,u,d=0,w+1,0,h+1
for i in range(n):
 si,ti=s[i],t[i]
 if l+1>=r or u+1>=d:break
 r=min(w+1,r+1)if ti=="L"else r
 l=max(0,l-1)if ti=="R"else l
 d=min(h+1,d+1)if ti=="U"else d
 u=max(0,u-1)if ti=="D"else u
 r-=1 if si=="R"else 0
 l+=1 if si=="L"else 0
 d-=1 if si=="D"else 0
 u+=1 if si=="U"else 0
print("YES"if l<sc<r and u<sr<d else"NO")
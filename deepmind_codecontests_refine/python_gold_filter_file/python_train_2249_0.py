n,m = map(int,input().split())
b=0
maxy=maxx=-1
miny=minx=max(m,n)-1
for i in range(n):
    s=str(input())
    for j in range(m):
        if s[j]=='B':
            b+=1
            minx=min(minx,j); maxx=max(maxx,j)
            miny=min(miny,i); maxy=max(maxy,i)
if b==0: print(1)
else:
    dx=maxx-minx+1; dy=maxy-miny+1
    d=max(dx,dy)
    if d>m or d>n: print(-1)
    else:
        t=d**2-b 
        print(t)

        
        
# if n==1 or m==1:
#     if n!=m: print(-1)
#     else:
#         s=str(input())
#         if s=='B': print(0)
#         else: print(1)

    #     xf=s.find('B')
    #     if xf!=-1:
    #         c=s[xf:].count('B'); b+=c 
    #         xl=m-s[::-1].find('B')-1
    #         minx=min(minx,xf); maxx=max(maxx,xl)
    #         miny=min(miny,i); maxy=max(maxy,i)
    # if b==0: print(1)
    # else:
    #     dx=maxx-minx+1; dy=maxy-miny+1
    #     d=max(dx,dy)
    #     if d>max(m,n):
    #         print(-1)
    #     else:
    #         t=d**2-b 
    #         print(t)

        
        

        
    #     xf=s.find('B')
    #     if xf!=-1: 
    #         c=s[xf:].count('B'); b+=c 
    #         xl=m-s[::-1].find('B')-1
    #         min_x=min(min_x,xf);max_x=max(max_x,xl)
    #         if min_y!=-1: max_y=i
    #         else: min_y=i
    # dx=(max_x-min_x+1); dy=(max_y-min_y+1)
    # d=max(dx,dy)
    # if (m and n)>=d:
    #     t=d**2-b
    #     print(t)
    # else: 
    #     print(-1)










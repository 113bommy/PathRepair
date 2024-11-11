w,h,x,y,r=map(int,input().split())
if w-r>=x and h-r>=y and x>=r and y>=r:
    print('Yes')
else:
    print('No')

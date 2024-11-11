for i in range (int(input())):
    r,g,b=map(int,input().split())
    count=0
    if(r>b+g+1):
        count+=1
    if(b>g+r+1):
        count+=1
    if(g>b+r+1):
        count+=1
    if(count==0):
        print("YES")
    else:
        print("NO")
        
def check(x,y):
    if x<y:
        return -1
    else:
        if x%2==0:
            x=x//2
        else:
            x=(x//2)+1
        while x%y!=0:
            x+=1
        return x
            
x,y=[int(i) for i in (input().split())]
print(check(x,y))
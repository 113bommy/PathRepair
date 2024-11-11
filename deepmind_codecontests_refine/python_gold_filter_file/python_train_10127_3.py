# Aditya Morankar
# lsta = list(map(int,input().split()))
def main():
    n,q = list(map(int,input().split()))
    lst = list(map(int,input().split()))
    
    operation = 0
    ans=0
    minn=0
    maxx=0
    for i in range(n):
        if operation==0:
            if i==0:
                maxx=lst[0]
            else:
                if lst[i] >= maxx:
                    maxx= lst[i]
                else:
                    operation=1
                    ans+=maxx
                    
                    minn = lst[i]
        else:
            if lst[i] <= minn:
                minn = lst[i]
            else:
                operation=0
                ans -= minn
                
                maxx = lst[i]
                
    if operation==0:
        ans+=maxx
    
    print(ans)
                
    
    
    
    

if __name__ == '__main__':
    t = int(input())
    while t!=0:
        main()
        t-=1
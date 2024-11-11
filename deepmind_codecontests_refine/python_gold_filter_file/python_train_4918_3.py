for i in range(int(input())):
    n,a,b=list(map(int,input().split()))
    x=''
    v=97
    for i in range(b):
        x+=chr(v)
        v+=1
    x+=(chr(v-1)*(a-b))
    for i in range(n):
        print(x[i%a],end="")
    print("")
        
        


for _ in range(int(input())):
    n,h=[*map(int,input().split())]
    a=[*map(int,input().split())]
    k=0
    def somme(k):
        s=k
        for i in range(0,n-1):
            s+= min((a[i+1]-a[i]),k)
        return s
    def binary(x,y):
        if x==y:
            return x
        elif somme((x+y)//2)<h:
            return binary(((x+y)//2)+1,y)
        else:
            return binary(x,((x + y) // 2))


    print(binary(k,h))
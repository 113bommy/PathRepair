n,a,b = list(map(int,input().split()))
l = list(map(int,input().split()))
l.sort(reverse=True)
x = l[a-1]
y = l[a]
print(x-y)
            



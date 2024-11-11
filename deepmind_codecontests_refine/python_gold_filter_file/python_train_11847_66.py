n,a,b = map(int,input().split())
diff = abs(a-b)
if diff%2==0:
    print(diff//2)
else:
    print(min(a-1,n-b)+1+(b-a-1)//2)

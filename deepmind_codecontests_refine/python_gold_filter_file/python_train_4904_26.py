n=int(input())
if n==1 or n==2:
    print('No')
    raise SystemExit
print ('Yes')
if n%2==0:
    print (1,int(n/2))
    print(n-1,(' '.join( [str(i) for i in range(1,n+1) if i!=n/2])))
else:
    print (1,int((n-1)/2+1))

    print (n-1,(' '.join([str(i) for i in range(1,n+1) if i!=(n-1)/2+1])))


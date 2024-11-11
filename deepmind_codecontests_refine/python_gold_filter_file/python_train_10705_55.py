N=input()
s=sum([int(i) for i in N])

print('Yes' if int(N)%s==0 else 'No')

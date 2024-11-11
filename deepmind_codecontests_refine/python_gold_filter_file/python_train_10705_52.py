n=input()
s=sum([int(i) for i in n])
print('Yes' if int(n)%s==0 else 'No')
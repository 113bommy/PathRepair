n=input()

p=len(n)
if len(set(n))==1:
    print(25*(p+1)+1)
else:
    print((26)*(p+1)-len(n))

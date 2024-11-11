a=int(input())
b=int(input())
p=len(format(b,"b"))
print(2**min(a,p)+b*(max(a-p,0)))
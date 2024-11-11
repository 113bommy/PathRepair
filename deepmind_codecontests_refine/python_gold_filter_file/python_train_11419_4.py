a=input()
x=len(a)
print([[x-1,x][a[:x//2]!=a[:-1-x//2:-1]],0][len({*a})<2])
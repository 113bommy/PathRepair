s=input()
k=10**(len(s)-1)
#print(s,str(int(s)//k*k-1))
print(sum(map(int,str((int(s)+1)//k*k-1))) if len(s)!=1 else s)
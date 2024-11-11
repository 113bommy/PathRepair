a=s=0
for x in[*open(0)][1].split():x=int(x);a+=s*x;s+=x
print(a%(10**9+7))
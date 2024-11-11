a,b,c=(input() for _ in range(3))
cnt=0
for i in range(1,int(a)+1):
    if(b[-i:]==c[:i]):cnt=i
print(2*int(a)-cnt)

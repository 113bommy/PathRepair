a,b=0,0
for i in input()+"Z":
    if i in ["A","C","G","T"]:
        a+=1
    else:
        b=max(b,a)
        a=0
print(b)
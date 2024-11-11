in1=input("").split()
in2=input("").split()
h=int(in1[1])
min_w=0
for i in in2:
    if int(i)>h:
        min_w+=2
    else:
        min_w+=1
print(min_w)
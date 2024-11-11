st1=input()
st2=input()
step=0
s=0
for i in st2:
    if i==st1[s]:
        s+=1
        step+=1
print(step+1)
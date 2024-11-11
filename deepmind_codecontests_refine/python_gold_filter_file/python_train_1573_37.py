i=int(input())
st=0
n=0
while n<i:
    n+= 2**st
    st+=1
print(st)

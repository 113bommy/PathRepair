n=int(input())
output=[]
for i in range(max(n-82,0),n):
    listi=list(map(int,str(i)))
    if(i+sum(listi)==n):
        output.append(i)
print(len(output))
for i in range(len(output)):
    print(output[i])
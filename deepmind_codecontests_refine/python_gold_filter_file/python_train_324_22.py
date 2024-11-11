n=int(input())
arr=sorted(list(map(int, input().split())))
even,odd=[],[]
for i in arr:
    if i%2==0:
        even.append(i)
    else:
        odd.append(i)
if(abs(len(even)-len(odd))<2):
    print(0)
elif(len(even)>len(odd)):
    print(sum(even[:len(even)-len(odd)-1]))
else:
    print(sum(odd[:len(odd)-len(even)-1]))
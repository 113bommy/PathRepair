x=int(input())
A=[]
for i in range(1,7):
    A.append(x//pow(2,7-i))
    x=x%pow(2,7-i)
A.append(x%2)
#print(A)

new=A[1]*pow(2,5)+A[6]*pow(2,4)+A[4]*pow(2,3)+A[3]*pow(2,2)+A[5]*pow(2,1)+A[2]
print(new)





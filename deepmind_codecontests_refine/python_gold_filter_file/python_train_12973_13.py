n=int(input())
if (n**0.5)%1==0:
    print(int(4*(n**0.5)))
else:
    count=0
    temp = int(n**0.5)+1
    temp2 = temp**2
    while temp2>=n:
        temp2-=temp
        count+=1
    print(int(2*(temp+temp-count+1)))

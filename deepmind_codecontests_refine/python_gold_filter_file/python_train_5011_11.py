# cook your dish here
# cook your dish here
n=int(input())
s=input()
y=[-1]
for i in s:
    if i=="R": 
        y.append(1)
    elif i=="B":
        y.append(2)
    else:
        y.append(3)

y.append(-1)
    
count=0
i=1
while i<=n:
    if y[i-1]!=y[i] and y[i]!=y[i+1]:
        i+=1
    else:
        j=i+1
        m=1
        while y[j]==y[j-1] and j<=n+2:
            j+=1
            m+=1
        if m%2==0:
            k=i
            while k<i+m:
                if (y[k-1]==2 or y[k]==2) and (y[k-1]==1 or y[k]==1):
                    y[k]=3
                elif (y[k-1]==2 or y[k]==2) and (y[k-1]==3 or y[k]==3):
                    y[k]=1
                elif (y[k-1]==1 or y[k]==1) and (y[k-1]==3 or y[k]==3):
                    y[k]=2
                else:
                    if y[k+1]==1:
                        y[k]=2
                    elif y[k+1]==2:
                        y[k]=3
                    else:
                        y[k]=1
                k+=2
                #print("yash",i)
        else:
            k=i+1
            
            
            while k<i+m:
                if y[k-1]==2:
                    y[k]=1
                elif y[k-1]==1:
                    y[k]=3
                else:
                    y[k]=2
                k+=2
                
        i=j
        count+=m//2

    
print(count)
for i in y:
    if i==1:
        print("R", end="")
    elif i==2:
        print("B", end="")
    elif i==3:
        print("G", end="")
        

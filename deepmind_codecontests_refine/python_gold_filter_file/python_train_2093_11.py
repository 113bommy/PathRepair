a=int(input())
b=list(map(int, input()))
sb=sum(b)
s = 1
for i in range (2, a+1):
        if sb%i == 0:
                bc=sb//i
                s=0
                for j in b:
                        s+=j
                        if s==bc:
                                s=0
                        if s>bc:
                                break
                if s==0:
                        break
if s==0: 
        print("YES")
else:
        print("NO")

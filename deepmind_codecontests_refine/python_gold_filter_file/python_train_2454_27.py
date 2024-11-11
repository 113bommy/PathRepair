a=int(input())
b=int(input())
c=int(input())
kompot=0
while a>=1 and b>=2 and c>=4:
    a-=1
    b-=2
    c-=4
    kompot+=7
print(kompot)

from sys import stdin
def exp(num1,num2,num3):
    op1= num1+num2*num3
    op2= num1*(num2+num3)
    op3= num1*num2*num3
    op4= (num1+num2)*num3
    op5= num1+num2+num3
    

    if op1>=op2 and op1>=op3 and op1>=op4 and op1>=op5:
        res= op1
    elif op2>=op1 and op2>=op3 and op2>=op4 and op2>=op5:
        res= op2
    elif op3>=op1 and op3>=op2 and op3>=op4 and op3>=op5:
        res= op3
    elif op4>=op1 and op4>=op2 and op4>=op3 and op4>=op5:
        res= op4
    else:
        res=op5
        

    print(res)

def main():
    num1=int(stdin.readline())
    num2=int(stdin.readline())
    num3=int(stdin.readline())

    exp(num1,num2,num3)
    
main()

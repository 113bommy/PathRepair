n=int(input())
d1={0:"zero",1:"one",2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",8:"eight",9:"nine",10:"ten",11:"eleven",12:"twelve",13:"thirteen",14:"fourteen",15:"fifteen",16:"sixteen",17:"seventeen",18:"eighteen",19:"nineteen"}
d2={2:"twenty",3:"thirty",4:"forty",5:"fifty",6:"sixty",7:"seventy",8:"eighty",9:"ninety"}
if n//10==0:
    print(d1[n])
elif n>=10 and n<20:
    print(d1[n])
else:
    if n//10>=2:
        print(d2[n//10],end="")
    if n%10!=0:
        print("-",end="")
        print(d1[n%10])




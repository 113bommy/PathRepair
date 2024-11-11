x = input()
l1 = ["zero","one","two","three","four","five","six","seven","eight","nine"]
l2 = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
l3 = ["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
r = ""
if (len(x)==1):
    r = r + l1[int(x)]
elif(len(x)==2 and x[1] != "0" and x[0]!="1"):
    r = r + l2[int(x[0])-2] + "-" + l1[int(x[1])]
elif(x[1]=="0" and x[0] != "1"):
    r = r + l2[int(x[0])-2]
else:
    r = r + l3[int(x[1])]

print(r)
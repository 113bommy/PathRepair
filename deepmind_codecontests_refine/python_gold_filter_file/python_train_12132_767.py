def bin1(num, s = ""):
    if num == 0:
        if s == "":
            return "0"
        else:
            return s
    s += str(int(num%2))
    num = num - num%2
    num = num / 2
    return bin1(num, s)
t = input()
st1 = bin1(int(t))

st = st1
st += "0"*(6-len(st1))
#print(st)  
num = int(st[5])*32+int(st[4])*1+int(st[3])*4+int(st[2])*8+int(st[1])*2+int(st[0])*16
print(num)
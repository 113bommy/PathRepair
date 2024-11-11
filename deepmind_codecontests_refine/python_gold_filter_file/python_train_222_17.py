l = int(input())
s = input()
zeros = s.count('0')
ones = l - zeros
if(zeros!=ones):
    print(1)
    print(s)
else:
    print(2)
    print(s[0:1]+" "+s[1:])
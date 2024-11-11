a = input()
s = a.split()
w = int(s[0])
h = int(s[1])
k = int(s[2])
answer = 0
while k!=0:
    answer = answer+ 2*(h-2)+2*(w-2)+4
    h = h-4
    w = w-4
    k = k-1
print (answer)
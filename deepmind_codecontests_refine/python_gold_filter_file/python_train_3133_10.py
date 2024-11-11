a = input()
b = input()
i = 1
while i < (min(len(a),len(b))+1):
    if a[i*-1] != b[i*-1]:
        break
    i+=1

print(len(a)+len(b)-2*(i-1))

x = input()
y = input()
left, right = x.split('|')
for i in y:
    if(len(left) < len(right)):
        left+=i
    else:
        right+=i
if(len(left)==len(right)):
    print("{}|{}".format(left, right))
else:
    print("Impossible")

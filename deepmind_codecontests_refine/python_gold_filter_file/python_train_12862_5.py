n = int(input())
bool = False
inputs = []
for i in range(n):
    inputs.append(input())
for i in range(n):
    v = inputs[i]
    if(bool == False):
        if(v[0] == "O" and v[1] == "O"):
            bool = True
            inputs[i] = "++" + v[2] + v[3] + v[4]
        elif(v[3] == "O" and v[4] == "O"):
            bool = True
            inputs[i] = v[0] + v[1] + v[2] + "++"
if bool == False:
    print("NO")
else:
    print("YES")
    for i in range(n):
        print(inputs[i])

inp = input()
res = eval(inp)

if (res >= 100):
    for i in range(res//100):
        print('+', end='')
    print("++++++++++++++++++++++++++++++++++++++++++++++++.>")
if (res >= 10):
    for i in range((res%100)//10):
        print('+', end='')
    print("++++++++++++++++++++++++++++++++++++++++++++++++.>")
for i in range(res%10):
    print('+', end='')
print("++++++++++++++++++++++++++++++++++++++++++++++++.")

t = int(input())
for k in range(t):
    l = int(input())
    s = input()
    stack = []
    count = 0
    i = 0
    while i < len(s):
        if s[i] == '(':
            stack.append(s[i])
            i+=1
        elif s[i] == ')' and len(stack) !=0 and stack[-1] == '(':
            stack.pop()
            i+=1
        else:
            s = s[0:i] + s[i+1:len(s)] + ')'
            count+=1

    # print(s)
    print(count)
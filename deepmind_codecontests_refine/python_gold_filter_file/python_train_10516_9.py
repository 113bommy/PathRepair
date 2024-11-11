ops={"+": lambda a, b: b + a,
        "-": lambda a, b: b - a,
        "*": lambda a, b: b * a,
        "/": lambda a, b: flaot(b)/a}
stack = []
for s in input().split():
    if s in ops:
        stack.append(ops[s](stack.pop(),stack.pop()))
    else:
        stack.append(int(s))
print(stack[-1])
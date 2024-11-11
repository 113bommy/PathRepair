import string

def get_min(a):
    for ind, x in enumerate(a):
        if x:
            return chr(ind + ord('a'))
    return None


s = input()
al = [s.count(x) for x in string.ascii_lowercase]
stack = []
i = 0
while i < len(s):
    if stack and stack[-1] <= get_min(al):
        print(stack.pop(), end='')
        continue
    stack.append(s[i])
    if s[i] == get_min(al):
        print(stack.pop(), end='')
    al[ord(s[i]) - ord('a')] -= 1
    i += 1
for i in stack[-1::-1]:
    print(i, end='')
    
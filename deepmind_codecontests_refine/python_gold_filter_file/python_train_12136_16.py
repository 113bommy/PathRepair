s_len = int(input())
s = input()
output_s = list()
if s_len % 2 != 0:
    for elem in range(0,s_len,2):
        output_s.insert(0,s[elem])
        try:
            output_s.append(s[elem+1])
        except: pass
else:
    for elem in range(0,s_len,2):
        output_s.append(s[elem])
        try:
            output_s.insert(0,s[elem+1])
        except: pass
print(''.join(output_s[::-1]))

s,t=[input() for i in range(2)]
print('Yes' if sorted(s)<sorted(t,reverse=True) else 'No')
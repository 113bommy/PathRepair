print((lambda s, c, a: "".join([s[s.find(i) + (1 if c == 'L' else -1)] for i in a]))("qwertyuiopasdfghjkl;zxcvbnm,./", input(), input()))

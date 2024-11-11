word = input()
Up = [x for x in word if x.isupper()]
Lo = [x for x in word if x.islower()]

if len(Up) > len(Lo):   print(word.upper())
else: print(word.lower())
#5C - longest brackets sequence
"""
The number of opening brackets '(' in our sequence that will later have to be
equivalised by closing brackets we start counting after we encounter the first '('
res - the length of the longest substring that maintains the rule, initially 0
b - the number of such substrings
s - stack of brackets that maintain the rule of a regular sequence
Note: we initialize the stack's index to be -1

Initially, a = 0 and we consider this to be a regular sequence already
"""
#We take input and immediately process each character introduced by the user
# for i, c in enumerate(input()):
res, b, s = 0, 1, [-1]
#Now we look through the all characters in the input:
for i, c in enumerate(input()):
	# print('ic', i, c)
    #When we find a '(', we push its index into the stack
	if c == '(': 
		s.append(i)
		# print('s len', s, len(s))
    #Else, if the stack is not empty, we pop an item from the stack
    #when finding an ')' paranthesis
	elif len(s) > 1:
        #We pop the previous opening bracket's index
		s.pop()
		# print('s pop', s)
        # n calculates the length of the current valid substring
        # by substracting the stack's top from the current index
		n = i - s[-1]
		# print('n', n)
        #Then we check if this length formed with base of 
            # current valid substring is more than max so far
        #If not, the number of valid substrings is 1
		if res < n: res, b = n, 1
        #If yes, then we add that to the number of substrings
		elif res == n: b += 1
    #If we can't find any regular sequence, the current index of the
        #stack is pushed as the base for the next possible valid substring
	else: s[0] = i
#Finally, we print the length of the longest valid sequence and the number
    #of such sequences
print (' '.join([str(res), str(b)]))

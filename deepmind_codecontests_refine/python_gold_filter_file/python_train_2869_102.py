test_case = int(input())
all_words= []

for _ in range(test_case):
	word = input()
	all_words.append(word)
	
for word in all_words:
	length_word = len(word)
	if(length_word <= 10):
		print(word)
	else:
		word_length = len(word[1:length_word-1])
		print(f'{word[0]}{word_length}{word[length_word-1]}')


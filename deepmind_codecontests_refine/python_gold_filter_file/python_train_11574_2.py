if __name__ == '__main__':
	n = int(input())
	# vowels: a, e, o, i, u
	vowels = 'aeoiu'
	words = []
	vocab1 = {}
	i = 0
	
	complete_pairs = []
	
	for _ in range(n):
		word = input()
		words.append(word)
		
		counter = 0
		last_letter = 'a'
		
		for letter in word:
			if letter in vowels:
				counter += 1
				last_letter = letter
		if (counter, last_letter) in vocab1:
			vocab1[(counter, last_letter)].append(i)
		else:
			vocab1[(counter, last_letter)] = [i]
		
		if len(vocab1[(counter, last_letter)]) >= 2:
			complete_pairs.append(
				(
					vocab1[(counter, last_letter)].pop(),
					vocab1[(counter, last_letter)].pop()
				))
			if len(vocab1[(counter, last_letter)]) == 0:
				vocab1.pop((counter, last_letter))
		i += 1
	
	# print(list(map(lambda x: '{}-{}'.format(words[x[0]], words[x[1]]), complete_pairs)))
	
	semicomplete_pairs = []
	vocab2 = {}
	
	for key in vocab1:
		if key[0] in vocab2:
			vocab2[key[0]].extend(vocab1[key])
		else:
			vocab2[key[0]] = vocab1[key]
	
		while len(vocab2[key[0]]) >= 2:
			semicomplete_pairs.append(
				(
					vocab2[key[0]].pop(),
					vocab2[key[0]].pop()
				)
			)
		if len(vocab2[key[0]]) == 0:
			vocab2.pop(key[0])
			
	result = []
	
	while len(semicomplete_pairs) >= 1 and  len(complete_pairs) >= 1:
	
		complete_pair = complete_pairs.pop()
		semicomplete_pair = semicomplete_pairs.pop()
		
		result.append((
			semicomplete_pair[0],
			complete_pair[0],
			semicomplete_pair[1],
			complete_pair[1]
		))
		
	while len(complete_pairs) >= 2:
	
		complete_pair1 = complete_pairs.pop()
		complete_pair2 = complete_pairs.pop()
		
		result.append((
			complete_pair1[0],
			complete_pair2[0],
			complete_pair1[1],
			complete_pair2[1]
		))
		
	print(len(result))
	
	for r in result:
		print('{} {}'.format(words[r[0]], words[r[1]]))
		print('{} {}'.format(words[r[2]], words[r[3]]))

		
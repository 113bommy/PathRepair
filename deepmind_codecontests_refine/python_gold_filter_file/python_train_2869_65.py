num_tests = int(input())
 
for x in range(0,num_tests):
  word = str(input())
  word_len = len(word)
  if word_len > 10:
    abbreviation = word[0] + str(len(word) - 2) + word[-1]
    print(abbreviation)
    continue
  print(word)
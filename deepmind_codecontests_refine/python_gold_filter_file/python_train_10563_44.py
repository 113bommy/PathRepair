n_and_m=list(map(int,input().split()))
list_of_words_in_both_language=[]
for i in range(n_and_m[1]):
	temp=list(map(str,input().split()))
	list_of_words_in_both_language.append(temp)

given_words=list(map(str,input().split()))

teacher_words=[]
short_word=[]
for i in list_of_words_in_both_language:
	temp=i[0]
	if(len(i[0])>len(i[1])):
		temp_short=i[1]
	else:
		temp_short=i[0]
	teacher_words.append(temp)
	short_word.append(temp_short)

for i in given_words:
	temp=teacher_words.index(i)
	print(short_word[temp]," ",end='')
